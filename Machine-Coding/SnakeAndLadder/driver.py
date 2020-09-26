from snake import Snake
from ladder import Ladder
from player import Player
from snake_ladder_service import SnakeAndLadderService
def main():
    snakes = []
    ladders = []
    players = []

    num_of_snakes = int(input("Enter the number of snakes\n"))

    while num_of_snakes:
        num_of_snakes-=1
        head,tail = input().split()
        snakes.append(Snake(int(head),int(tail)))
    
    num_of_ladders = int(input())

    while num_of_ladders:
        num_of_ladders-=1
        start,end = input().split()
        ladders.append(Ladder(int(start),int(end)))
    
    num_of_players = int(input())

    while num_of_players:
        num_of_players-=1
        name = input()
        players.append(Player(name))
    
    snake_and_ladder_game_service = SnakeAndLadderService(snakes,ladders,players,100)
    snake_and_ladder_game_service.start_game()

if __name__ == "__main__":
    main()