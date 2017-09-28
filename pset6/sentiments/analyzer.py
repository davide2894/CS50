import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positive = set()
        self.negative= set()
        file1 = open(positives, "r")
        file2 = open(negatives, "r")
        for line in file1:
            self.positive.add(line.rstrip("\n"))
        for line in file2:
            self.negative.add(line.rstrip("\n"))


    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score  = 0
        for token in tokens:
            if(token.lower() in self.positive):
                score += 1
            elif(token.lower() in self.negative):
                score  -= 1
            else:
                score  += 0
        return score


