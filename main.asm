DATA SEGMENT USE16
    MESG DB 'Hello word','$'
DATA ENDS
CODE SEGMENT USE16
         ASSUME CS:CODE,DS:DATA

        
    BEG: 
         MOV    AX,DATA
         MOV    DS,AX
         MOV    AH,9
         MOV    DX, OFFSET MESG
         INT    21H
         MOV    AH,4CH
         INT    21H                ;back to dos

CODE ENDS
END BEG