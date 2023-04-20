<!DOCTYPE html>
<html lang="en">

<head id = "head">
    <style>
        #Bhelp{
            color:#0000FF;
            background-color: red;           
        }
        #but{
            color:#000000;
            background-color: black;    
        }
        #cir{
            background-color: black;
            width: 30px;
            height: 30px;
            border-radius: 100%;
            
            line-height: 30px;
            font-size: 10px;  
            position: relative;
            left: 10px;
            transition:  all 1s linear;
            top: 10px;
        }
    </style>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <script src="nodejs/brain.js"></script>
    <script src="dataset.js"></script>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body bgcolor = "#FFFFFF">
    <button id = "but">yisell</button>
</body>
<script>

    function log(...params) {
        console.log(...params)
    }
    function $(id){
        return  document.getElementById(id)
    }
</script>
<script>
    var elem = document.createElement('div');
    elem.className = 'cir'
    elem.id = 'cir'
    elem.innerText = 'node'
    document.body.appendChild(elem)
    window.addEventListener("mousemove", mov)
    function mov(ev) {
        var x = ev.pageX,y = ev.pageY
        elem.style.left = x + 'px'
        elem.style.top = y + 'px'
    }
</script>

<?php

?>    
</html>