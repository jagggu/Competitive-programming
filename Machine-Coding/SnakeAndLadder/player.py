import uuid

class Player(object):
    
    def __init__(self,name):

        self.__name = name
        self.__id = name + ": " + str(uuid.uuid1())
        self.__current_pos = 0
    
    def get_name(self):
        return self.__name
    
    def get_id(self):
        return self.__id
    
    def get_position(self):
        return self.__current_pos
    
    def set_position(self,position):
        self.__current_pos = position

