import sys
import requests
import json

#if len(sys.argv) != 1:
    #return "Wrong number of arguments"

def getRequest(url):
    #Making the request

    res = requests.get(url)

    resList = []

    #Converting to list so '[' and ']' can be removed
    for i in res.text: 
        resList.append(i)

    resList.pop(0)
    resList.pop(-1)

    return res.text

def getItemFromJSON(JSON, item): 
    dataJSON = json.loads(JSON)
    if dataJSON[item]:
        return dataJSON[item]
    else:
        return "Item not in JSON"
    return JSON

def getASTFromMatch(url):
    #url = 'http://livescores.worldsnookerdata.com/Matches/Result/14178/780441'

    r = requests.get(url)

    ast_p1_index = r.text.find('<p class="score score-player1 score-ast score-ast-left text-right">') + 67
    ast_p1 = r.text[ast_p1_index:ast_p1_index+4]

    ast_p2_index = r.text.find('<p class="score score-player2 score-ast">') + 41
    ast_p2 = r.text[ast_p2_index:ast_p2_index+4]

    return_str = ast_p1 + ":" + ast_p2

    #print(return_str)

    return return_str
    