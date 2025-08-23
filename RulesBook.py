class RulesBook:
    def __init__(self):
        self.rules = [0 for _ in range(8)] 

    def get_rules(self) -> list:
        return self.rules
    
    def set_rules(self, new_rules: list, col: int):
        print("Setting new rules...")
        self.rules[col] = new_rules
        print(self.get_rules())