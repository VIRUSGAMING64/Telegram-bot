import zipfile
import os


def div(rute, TP,prof = 0):
    if prof == 2:
        return 
    try:
        dir, name = os.path.split(rute)
        Dp = os.path.join(dir, f"{name}_partes")
        os.makedirs(Dp, exist_ok=True)
        with zipfile.ZipFile(rute, "r") as archivo_zip:
            num_partes = (archivo_zip.infolist()[0].file_size - 1) // TP + 1
            for i in range(num_partes):
                start = i * TP
                end = min((i + 1) * TP, archivo_zip.infolist()[0].file_size)
                nombre_parte = f"{name}_parte{i+1}.zip"
                with zipfile.ZipFile(os.path.join(Dp, nombre_parte), "w") as parte_zip:
                    for archivo_info in archivo_zip.infolist():
                        archivo_data = archivo_zip.read(archivo_info.filename)
                        parte_zip.writestr(archivo_info, archivo_data[start:end])
                print(f"Parte {i+1}: {nombre_parte} creada.")
        print("División del archivo completada.")
    except Exception as e:
        if(str(e) == "File is not a zip file"):
            Z = zipfile.ZipFile(rute+".zip","w",allowZip64=1,compresslevel=3)
            Z.write(rute)
            div(rute+".zip",TP,prof+1)
        else:
            print(e)
div(os.getcwd()+"\\telegram bot\\utils.py",256)