
class Split(object):

    def __init__(self,user):
        self.user = user
        self.amount = 0.0
    
    def get_user(self):
        return self.user
    
    def set_user(self,user):
        self.user = user
    
    def get_amount(self):
        return self.amount
    
    def set_amount(self,amount):
        self.amount = amount