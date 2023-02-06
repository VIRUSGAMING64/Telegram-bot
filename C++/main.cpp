#define UNICODE 1
#define _UNICODE 1

/* The code of interest is in the subroutine GetDriveGeometry. The
   code in main shows how to interpret the results of the call. */
#include <bits/stdc++.h>
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
/*
10279
*/
#define wszDrive "\\\\.\\PhysicalDrive0"
using namespace std;
BOOL GetDriveGeometry(LPCSTR wszPath,DISK_GEOMETRY* pdg)
{
    HANDLE hDevice = INVALID_HANDLE_VALUE;  // handle to the drive to be examined 
    BOOL bResult = FALSE;                 // results flag
    DWORD junk = 0;                     // discard results

    hDevice = CreateFileA(wszPath,          // drive to open
        0,                // no access to the drive
        FILE_SHARE_READ | // share mode
        FILE_SHARE_WRITE,
        NULL,             // default security attributes
        OPEN_EXISTING,    // disposition
        0,                // file attributes
        NULL);            // do not copy file attributes

    if(hDevice == INVALID_HANDLE_VALUE)    // cannot open the drive
    {
        return (FALSE);
    }

    bResult = DeviceIoControl(hDevice,                       // device to be queried
        IOCTL_DISK_GET_DRIVE_GEOMETRY, // operation to perform
        NULL,0,                       // no input buffer
        pdg,sizeof(*pdg),            // output buffer
        &junk,                         // # bytes returned
        (LPOVERLAPPED)NULL);          // synchronous I/O

    CloseHandle(hDevice);

    return (bResult);
}


int main()
{
    DISK_GEOMETRY pdg = {0}; // disk drive geometry structure
    BOOL bResult = FALSE;      // generic results flag
    ULONGLONG DiskSize = 0;    // size of the drive, in bytes

    bResult = GetDriveGeometry(wszDrive,&pdg);
    if(bResult)
    {
        printf("Drive path      = %ws\n",wszDrive);
        printf("Cylinders       = %I64d\n",pdg.Cylinders);
        printf("Tracks/cylinder = %ld\n",(ULONG)pdg.TracksPerCylinder);
        printf("Sectors/track   = %ld\n",(ULONG)pdg.SectorsPerTrack);
        printf("Bytes/sector    = %ld\n",(ULONG)pdg.BytesPerSector);
        DiskSize = pdg.Cylinders.QuadPart * (ULONG)pdg.TracksPerCylinder *
            (ULONG)pdg.SectorsPerTrack * (ULONG)pdg.BytesPerSector;
        printf("Disk size       = %I64d (Bytes)\n                = %.2f (Gb)\n",
            DiskSize,(double)DiskSize / (1024 * 1024 * 1024));
        cout << "MEDIA type:\t" << pdg.MediaType<< endl;
    }
    else
    {
        printf("GetDriveGeometry failed. Error %ld.\n",GetLastError());
    }

    return ((int)bResult);
}