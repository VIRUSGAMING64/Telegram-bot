function find(){
    param($path)
    echo $path
    if($path -eq "dota"){
        echo "IGUALL"
    }
    try{
        cd $path
    }catch{
        return
    }
    $dirs = ls
    $i = 0
    while(1){
        if($dirs.name[$i] -eq $NULL){
            $i = 0
            break
        }
        find($dirs.name[$i])
    }
}