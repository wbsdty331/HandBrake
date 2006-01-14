/* $Id: HBInternal.h,v 1.10 2004/05/12 17:21:24 titer Exp $

   This file is part of the HandBrake source code.
   Homepage: <http://handbrake.m0k.org/>.
   It may be used under the terms of the GNU General Public License. */

#ifndef HB_INTERNAL_H
#define HB_INTERNAL_H

#include "HandBrake.h"
#include "Fifo.h"
#include "Mux.h"
#include "Thread.h"
#include "Work.h"

#ifndef HB_CYGWIN
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

/* Demuxer */
HBDVDRead * HBDVDReadInit( HBHandle *, HBTitle * );
void        HBDVDReadClose( HBDVDRead ** );

/* Decoders */
HBWork * HBMpeg2DecInit( HBHandle *, HBTitle * );
void     HBMpeg2DecClose( HBWork ** );
HBWork * HBAc3DecInit( HBHandle *, HBAudio * );
void     HBAc3DecClose( HBWork ** );
HBWork * HBLpcmDecInit( HBHandle *, HBAudio * );
void     HBLpcmDecClose( HBWork ** );
HBWork * HBMpgaDecInit( HBHandle *, HBAudio * );
void     HBMpgaDecClose( HBWork ** );

/* Scaler */
HBWork * HBScaleInit( HBHandle *, HBTitle * );
void     HBScaleClose( HBWork ** );

/* Resampler */
HBWork * HBResampleInit( HBHandle *, HBAudio * );
void     HBResampleClose( HBWork ** );

/* Encoders */
HBWork * HBFfmpegEncInit( HBHandle *, HBTitle * );
void     HBFfmpegEncClose( HBWork ** );
HBWork * HBXvidEncInit( HBHandle *, HBTitle * );
void     HBXvidEncClose( HBWork ** );
HBWork * HBX264EncInit( HBHandle *, HBTitle * );
void     HBX264EncClose( HBWork ** );
HBWork * HBMp3EncInit( HBHandle *, HBAudio * );
void     HBMp3EncClose( HBWork ** );
HBWork * HBFaacEncInit( HBHandle *, HBAudio * );
void     HBFaacEncClose( HBWork ** );
HBWork * HBVorbisEncInit ( HBHandle *, HBAudio * );
void     HBVorbisEncClose( HBWork ** );

/* Scanner */
HBScan * HBScanInit( HBHandle *, const char * device, int title );
void     HBScanClose( HBScan ** );

/* Called by HBScan to tell the GUI how far we've been */
void HBScanning( HBHandle *, int title, int titleCount );

/* Called by HBScan. titleList is a list of all valid titles which
   should be shown on the interface */
void HBScanDone( HBHandle *, HBList * titleList );

/* Used to create temporary files (/tmp/HB.pid.whatever) */
int  HBGetPid( HBHandle * );

/* Called by every thread involved in the rip process. Returns
   immediately is rip isn't paused, blocks until the rip is resumed
   otherwise */
void HBCheckPaused( HBHandle * );

/* Called by the decoders when the last packet is being proceeded */
void HBDone( HBHandle * );

/* Called by the video encoder to update the GUI progress */
void HBPosition( HBHandle *, float );

/* Called by any thread which couldn't continue and asks to stop */
void HBErrorOccured( HBHandle *, int error );

#endif
