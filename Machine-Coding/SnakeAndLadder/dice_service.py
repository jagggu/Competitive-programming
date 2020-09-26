import random

class DiceService(object):

    def __init__(self,size):

        self.__size = size
    
    def roll(self):
        dice_number = random.randint(1,self.__size)
        
        return dice_number