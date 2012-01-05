// Copyright (c) 2011, XMOS Ltd, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

#ifndef KCAM_GRABBER_H_
#define KCAM_GRABBER_H_

#include <platform.h>

#define uint unsigned

void KCAM_reset();
void kcam_run(void);
void GrabFrame128x128HVSub(in port p_href, in port p_vsync, buffered in port:32 p_DIN32);
void Grab64x40BlocksSUB(in port p_href, in port p_vsync, buffered in port:32 p_DIN32, chanend pixels);
void ImProc(chanend pixels);

#endif /*KCAM_GRABBER_H_*/
