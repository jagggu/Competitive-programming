
from split import Split

class PercentSplit(Split):
    def __init__(self,user,percent):
        Split.__init__(self,user)
        self.percent = percent