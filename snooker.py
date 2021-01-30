import sys
import requests
import json

#if len(sys.argv) != 1:
    #return "Wrong number of arguments"

def getRequest(param):
    #Making the request
    url = "http://api.snooker.org/?e=398"
    res = requests.get(url)

    resList = []

    #Converting to list so '[' and ']' can be removed
    for i in res.text: 
        resList.append(i)

    resList.pop(0)
    resList.pop(-1)

    return res.text;
    return json.loads("".join(resList))
