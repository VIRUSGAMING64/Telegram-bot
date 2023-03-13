import os
import os.path as path
import threading as th


class loger:
    file_log_name = None
    file_size = None

    @classmethod
    def __init__(self):
        print("loger created empty")

    @classmethod
    def __init__(self, file):
        if path.exists(file):
            print("loaded exists log file")
            self.file_log_name = file
        else:
            print("creating new log file")
            file = open(file, 'w')
            file.close()

    @classmethod
    def CreateNew(self, file):
        new = loger(file)
        self = new
        return new

    @classmethod
    def write(self, data: str):
        file = open(self.file_log_name, "a")
        file.write(data+"\n")
        file.close()

    @classmethod
    def read(self):
        file = open(self.file_log_name, "r")
        line = file.read(65536)
        text: str = line
        while line:
            line = file.read(65536)
            text += line
        file.close()
        return text

    @classmethod
    def decode(self, text):
        list = []
        str = ""
        for i in range(len(text)):
            if text[i] == "[":
                str = ""
                continue
            if text[i] == "]":
                list.append(str)
                str = ""
                continue
            str += text[i]
        return list

    def decode_list(self, lista):
        result = []
        for data in lista:
            str = ""
            res = []
            for i in range(len(data)):
                if data[i] == ",":
                    res.append(str)
                    str = ""
                    continue
                str += data[i]
            res.append(str)
            result.append(res)
        return result


print("loger library loaded...")
