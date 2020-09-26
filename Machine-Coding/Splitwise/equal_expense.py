
from expense import Expense

class EqualExpense(Expense):

    def __init__(self,amount,paid_by,splits):
        Expense.__init__(self,amount,paid_by,splits)
    
    