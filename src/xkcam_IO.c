// Copyright (c) 2011, XMOS Ltd, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

#include <stdio.h>
#include <syscall.h>
#include <string.h>

void pgmout(int data[], int xWd, int yHt, char fname[])
{
    int fd, hdrln;
    char hdr[ 64 ];

    sprintf( hdr, "P5\n%d %d\n255\n", xWd, yHt );
    hdrln = strlen( hdr );
	printf( "Writing %s\n", fname );

	fd = _open( fname, O_WRONLY | O_CREAT | O_BINARY, 0644 );
    _write( fd, hdr, hdrln );
    _write( fd, (void *)data, xWd * yHt );
    _close( fd );
}

void savefmeans( uint fmeans[], uint fcnt )
{
	FILE *fp = fopen( "../output/fmeans.txt", "wt" );
	for( int i = 0; i < fcnt; i++ )
	{
		fprintf( fp, "%d\n", fmeans[ i ] );
	}
	fclose( fp );
}