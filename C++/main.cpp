#define UNICODE 1
#define _UNICODE 1
#include <bits/stdc++.h>
#include <windows.h>
#include <winioctl.h>
#include <stdio.h> 
#define wszDrive "\\\\.\\c:"
using namespace std;
BOOL GetDriveGeometry(LPCSTR wszPath,DISK_GEOMETRY* pdg)
{
    HANDLE hDevice = INVALID_HANDLE_VALUE; 
    BOOL bResult = FALSE;          
    DWORD junk = 0;                

    hDevice = CreateFileA(
        wszPath, 
        0,                
        FILE_SHARE_READ |
        FILE_SHARE_WRITE,
        NULL,            
        OPEN_EXISTING,   
        0,               
        NULL);            

    if(hDevice == INVALID_HANDLE_VALUE)    
    {
        return (FALSE);
    }

    bResult = DeviceIoControl(
        hDevice,                       // device to be queried
        IOCTL_DISK_GET_DRIVE_GEOMETRY, // operation to perform
        NULL,
        0,                       // no input buffer
        pdg,
        sizeof(*pdg),            // output buffer
        &junk,                         // # bytes returned
        (LPOVERLAPPED)NULL);          // synchronous I/O

    CloseHandle(hDevice);

    return (bResult);
}

int main()
{
    DISK_LOGGING logdisk = {0};
    DISK_GEOMETRY pdg = {0}; // disk drive geometry structure
    BOOL bResult = FALSE;      // generic results flag
    ULONGLONG DiskSize = 0;    // size of the drive, in bytes
    bResult = GetDriveGeometry(wszDrive,&pdg);
    DWORD len = 64;
    LPSTR name;
    GetVolumeNameForVolumeMountPointA("d:\\",name,MAX_PATH);
    cout << name << endl;
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
        cout << "MEDIA type:\t" << pdg.MediaType << endl;
    }
    else
    {
        printf("GetDriveGeometry failed. Error %ld.\n",GetLastError());
    }
    return 0;
    
}

