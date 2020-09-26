
class Expense(object):

    def __init__(self,amount,paid_by,splits):
        self.paid_by = paid_by
        self.splits = splits
        self.amount = amount
    
    def get_splits(self):
        return self.splits
    
    
    