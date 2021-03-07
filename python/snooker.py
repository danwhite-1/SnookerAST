import sys
import requests
import json

#if len(sys.argv) != 1:
    #return "Wrong number of arguments"

def getRequest(url):
    #Making the request
    #print(url) #for debugging
    res = requests.get(url)

    resList = []

    #Converting to list so '[' and ']' can be removed
    for i in res.text: 
        resList.append(i)

    resList.pop(0)
    resList.pop(-1)

    #print(res.text) #for debugging
    return res.text

def getItemFromJSON(JSON, item): 
    dataJSON = json.loads(JSON)
    if dataJSON[item]:
        return str(dataJSON[item]) #Need to explicitly return as str, to prevent IDs being cast as int
    else:
        return "Item not in JSON"

def getASTFromMatch(url): #Would be good to add a check for not found - index == -1
    #url = 'http://livescores.worldsnookerdata.com/Matches/Result/14178/780441'

    r = requests.get(url)
    #print(r.text)

    ast_p1_index = r.text.find('<p class="score score-player1 score-ast score-ast-left text-right">') + 67
    ast_p1 = r.text[ast_p1_index:ast_p1_index+4]

    ast_p2_index = r.text.find('<p class="score score-player2 score-ast">') + 41
    ast_p2 = r.text[ast_p2_index:ast_p2_index+4]

    return_str = ast_p1 + ":" + ast_p2

    #print(return_str)

    return return_str
    