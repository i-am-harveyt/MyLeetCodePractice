class Trie:

    def __init__(self):
        self.trie = dict()

    def insert(self, word: str) -> None:
        for i in range(len(word)):
            cur: str = word[:i]
            if cur in self.trie:
                continue
            self.trie[cur] = False
        self.trie[word] = True

    def search(self, word: str) -> bool:
        return word in self.trie and self.trie[word]

    def startsWith(self, prefix: str) -> bool:
        return prefix in self.trie

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
