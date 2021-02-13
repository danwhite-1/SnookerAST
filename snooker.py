import sys
import requests
import json

#if len(sys.argv) != 1:
    #return "Wrong number of arguments"

def getRequest(param):
    #Making the request
    #url = "http://api.snooker.org/?e=397&r=1&n=5"
    #res = param;
    #return param;
    res = requests.get(param)

    resList = []

    #Converting to list so '[' and ']' can be removed
    for i in res.text: 
        resList.append(i)

    resList.pop(0)
    resList.pop(-1)

    return res.text;

def getItemFromJSON(JSON, item): 
    dataJSON = json.loads(JSON)
    if dataJSON[item]:
        return dataJSON[item];
    else:
        return "Item not in JSON"
    return JSON
