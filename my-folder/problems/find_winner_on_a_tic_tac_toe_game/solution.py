class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        won = 0
        board = [[0,0,0],[0,0,0],[0,0,0]]
        temp = 0
        for x in moves :
            if(temp%2 == 0):
                board[x[0]][x[1]] = 1
            else:
                board[x[0]][x[1]] = 2
            temp=temp+1

        moves=board
        print(moves)
        for i in range(0,3):
            if(moves[0][i] != 0 and (moves[0][i]==moves[1][i] and moves[0][i]==moves[2][i])):
                won=moves[0][i]
                break
            if(moves[i][0] != 0 and (moves[i][0]==moves[i][1] and moves[i][0]==moves[i][2])):
                won=moves[i][0]
                break
            
        if((moves[0][0]==moves[1][1] and moves[0][0]==moves[2][2]) or moves[0][2]==moves[1][1] and moves[1][1]==moves[2][0]):
            won=moves[1][1]

        if(won==0):
            if(temp<9):
                return "Pending"
            return "Draw"
        elif(won==1):
            return "A"
        elif(won==2):
            return "B"
        