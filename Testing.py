#This script returns the AST of players in a snooker match

import requests

def getASTFromMatch():
    url = 'http://livescores.worldsnookerdata.com/Matches/Result/14178/780441'
    r = requests.get(url)

    ast_p1_index = r.text.find('<p class="score score-player1 score-ast score-ast-left text-right">') + 67
    ast_p1 = r.text[ast_p1_index:ast_p1_index+4]

    ast_p2_index = r.text.find('<p class="score score-player2 score-ast">') + 41
    ast_p2 = r.text[ast_p2_index:ast_p2_index+4]

    return ast_p1, ast_p2

print("Player 1 AST: ",getASTFromMatch()[0],"\nPlayer 2 AST: ",getASTFromMatch()[1])
