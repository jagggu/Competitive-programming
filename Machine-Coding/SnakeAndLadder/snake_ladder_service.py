import time
from board import Board
from dice_service import DiceService
class SnakeAndLadderService(object):

    def __init__(self,snakes,ladders,players,size):
        self.__is_game_completed = False
        self.__should_game_continue_till_last_player = False
        self.__snakes = snakes
        self.__ladders = ladders
        self.__players = players
        self.__size = size
    
    def start_game(self):
        snake_and_ladder_board = Board(self.__size)
        snake_and_ladder_board.set_ladders(self.__ladders)
        snake_and_ladder_board.set_players(self.__players)
        snake_and_ladder_board.set_snakes(self.__snakes)
        
        players_queue = self.__players
        dice = DiceService(6)
        while self.__is_game_completed == False:

            player = players_queue.pop(0)
            if len(players_queue) == 0:
                    self.__is_game_completed = True
                    continue
            die_rolled,new_position = self.move_player(player,dice)

            if new_position == self.__size:
                
                print("Player: {} won the game".format(player.get_name()))
            else:
                print("{} rolled a {} and moved from {} to {}.".format(player.get_name(),die_rolled,player.get_position(),new_position))
                player.set_position(new_position)
                players_queue.append(player)
            time.sleep(2)

    
    def move_player(self,player,dice):
        die_number = dice.roll()

        player_current_position = player.get_position()

        new_position = player_current_position + die_number

        if new_position > self.__size:
            return die_number,player_current_position

        previous_position = -1

        while previous_position != new_position:
            previous_position = new_position

            for snake in self.__snakes:
                if new_position == snake.get_head():
                    new_position = snake.get_tail()
            
            for ladder in self.__ladders:
                if new_position == ladder.get_start():
                    new_position = ladder.get_end()
        
        return die_number,new_position


        
    
