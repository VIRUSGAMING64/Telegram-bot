import requests as rq
import time
import random
import hashlib
from values import *
key = "1c361ffcdc858caad9ac5d4db9fcc50df243391d" 
sec = "80300ef0668cfafece6c373dc95ef47ac0319de8"


class codeforces:
    apikey = None
    def __init__(self,apikey:str,secret:str|None=None):
        self.apikey = apikey
        self.secret = secret

    def comments(self,blogid:int):
        asw = self.get("blogEntry.comments","blogEntryId=79")
        for i in range(len(asw)):
            asw[i] = to_comment(asw[i])
        return asw

    def contestlist(self,gym:bool=False):
        arg = "gym=true"
        if gym == False:
            arg=""
        asw = self.get("contest.list",arg)
        for i in range(len(asw)):
            asw[i] = to_contest(asw[i])
        return asw
    def recentActions(self,maxcount:int):
        if(maxcount < 1 or maxcount > 100):
            raise "we need 1 <= maxcount <= 100"
        asw = self.get("recentActions",f"maxCount={maxcount}")
        for i in range(len(asw)):
            asw[i] = to_recentaction(asw[i])
        return asw
    def get(self,metod,args) -> list:
        rand = int(random.random()*10**6)
        args= f"{metod}?{args}"
        args= args+f"&apikey={self.apikey}&time={int(time.time())}"
        mhash = hashlib.sha512(f"{rand}/{args}#{self.secret}".encode()).hexdigest()
        args += f"&apiSig={rand}{mhash}"
        url = f"https://codeforces.com/api/{args}"
        ret =rq.get(url)
        if ret.status_code != 200:
            return ret
        ret = dict(ret.json())["result"]
        return ret
    
cf = codeforces(key,sec)
