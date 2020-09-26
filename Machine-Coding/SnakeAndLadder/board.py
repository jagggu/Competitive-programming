
class Board(object):

    def __init__(self,size):

        self.__size = size
        self.__snakes = []
        self.__ladders = []
        self.__players = []
    
    def get_size(self):
        return self.__size
    
    def get_snakes(self):
        return self.__snakes
    
    def get_ladders(self):
        return self.__ladders
    
    def get_players(self):
        return self.__players
    
    def set_snakes(self,snakes):
        self.__snakes = snakes
    
    def set_ladders(self,ladders):
        self.__ladders = ladders
    
    def set_players(self,players):
        self.__players = players