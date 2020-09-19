//
//  main.m
//  FLD12_CommandLineTool
//
//  Created by PeterCoolAssHuber on 2017-09-16.
//  Copyright © 2017 Peter Huber. All rights reserved.
//

// Note that the versions of OUTENG and OUTMET contained in this project fix the issue uncovered by DLL use where subsequent runs of the same input file yield different output files. This only occurs when the program is still in memory for multiple runs and is caused by the use of "uninitialized" local variables. (In all fairness, the routines were not meant to be reentrant and count on the fact that "static" local vars are automaticlaly initialized to 0 on program start (but keep their previous values on subsequent runs). This was solved by explicitly initializing all local variables in the "main" functions of OUTENG and OUTMET to 0.)

// The caller can specify the flag '-m' to get output in metric instrad of the default imperial system.

#import <Foundation/Foundation.h>

#import "PCH_Logging.h"
#include "f2c.h"
#include <unistd.h>

// Declarations for FLD12 functions
int INP12MAIN__(char *baseDirectory);
int FLD8MAIN__(char *baseDirectory);
int OUTENGMAIN__(char *baseDirectory);
int OUTMETMAIN__(char *baseDirectory);
int FIELDPRPMAIN__(char *baseDirectory);

int main(int argc, char * argv[]) {
    @autoreleasepool {
        
        // default to Inch output
        bool useInch = true;
        
        int opt;
        while ((opt = getopt(argc, argv, "m")) != -1)
        {
            switch (opt) {
                case 'm':
                    useInch = false;
                    break;
                default:
                    fprintf(stderr, "Usage: %s [-m] input_file_name\n", argv[0]);
                    return -1;
                    break;
            }
        }
        
        if (optind >= argc)
        {
            ALog(@"Missing file name in call to FLD12");
            return -1;
        }
        
        NSString *filePath = [NSString stringWithUTF8String:argv[optind]];
        
        if (filePath == NULL)
        {
            ALog(@"Illegal file name in call to FLD12");
            return -1;
        }
        
        NSFileManager *fileMgr = [NSFileManager defaultManager];
        
        if (![fileMgr fileExistsAtPath:filePath])
        {
            ALog(@"File '%@' does not exist!", filePath);
            return -1;
        }
        
        // save the file name with and without extensions
        NSString *fileNameWithExtension = [filePath lastPathComponent];
        NSString *fileNameNoExtension = [fileNameWithExtension stringByDeletingPathExtension];
        
        NSString *userTempDir = NSTemporaryDirectory();
        
        // We need to make sure that the ATPCM file exists in the temporary directory. If it doesn't, we will assume that the file exists in the user's Documents folder and copy it to the temp folder.
        
        NSString *tempATPCM = [NSString stringWithFormat:@"%@ATPCM.FIL", userTempDir];
        if (![fileMgr fileExistsAtPath:tempATPCM])
        {
            NSArray *docDir = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
            NSString *srcATPCM = [NSString stringWithFormat:@"%@/ATPCM.FIL", docDir[0]];
            
            NSError *wError;
            
            if (![fileMgr copyItemAtPath:srcATPCM toPath:tempATPCM error:&wError])
            {
                ALog(@"Error copying ATPCM.FIL. %@", wError.localizedDescription);
                return -1;
            }
        }
        
        NSString *inp1Fil = [NSString stringWithFormat:@"%@INP1.FIL", userTempDir];
        
        NSError *wError;
        
        [fileMgr removeItemAtPath:inp1Fil error:&wError];
        
        // get rid of any CRs there may be in the godamned file
        NSString *inFileString = [[NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:&wError] stringByReplacingOccurrencesOfString:@"\r" withString:@""];
        
        // normally, we only run this loop once (i<2), but for debugging of the "static local vars" issue discussed above, set i<3 (or more) for multiple runs with the same inpu file
        for (int i = 1; i<2; i++)
        {
            if (![inFileString writeToFile:inp1Fil atomically:NO encoding:NSUTF8StringEncoding error:&wError])
            {
                ALog(@"Error creating INP1.FIL. %@", wError.localizedDescription);
                return -1;
            }
            
            if (INP12MAIN__((char *)[userTempDir cStringUsingEncoding:NSUTF8StringEncoding]) != 0)
            {
                ALog(@"Error in Inp12. %@", wError.localizedDescription);
                return -1;
            }
            
            if (FLD8MAIN__((char *)[userTempDir cStringUsingEncoding:NSUTF8StringEncoding]) != 0)
            {
                ALog(@"Error in Fld8. %@", wError.localizedDescription);
                return -1;
            }
            
            if (useInch)
            {
                if (OUTENGMAIN__((char *)[userTempDir cStringUsingEncoding:NSUTF8StringEncoding]) != 0)
                {
                    ALog(@"Error in OutEng. %@", wError.localizedDescription);
                    return -1;
                }
            }
            else
            {
                if (OUTMETMAIN__((char *)[userTempDir cStringUsingEncoding:NSUTF8StringEncoding]) != 0)
                {
                    ALog(@"Error in OutEng. %@", wError.localizedDescription);
                    return -1;
                }
            }
            
            
            if (FIELDPRPMAIN__((char *)[userTempDir cStringUsingEncoding:NSUTF8StringEncoding]) != 0)
            {
                ALog(@"Error in FieldPrep. %@", wError.localizedDescription);
                return -1;
            }
            
            
            NSString *resultFile = [NSString stringWithFormat:@"%@/%@_%d.ANDOUT", [filePath stringByDeletingLastPathComponent], fileNameNoExtension, i];
            
            [fileMgr removeItemAtPath:resultFile error:&wError];
            
            if (![fileMgr copyItemAtPath:[NSString stringWithFormat:@"%@OUTPUT", userTempDir] toPath:resultFile error:&wError])
            {
                ALog(@"Error creating result file. %@", wError.localizedDescription);
                return -1;
            }
        }
    }
    
    return 0;
}
