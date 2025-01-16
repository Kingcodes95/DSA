# need to create a dictionary with empty key values initialized
        anagram_map = defaultdict(list)

        # iterate each word in the list
        for word in strs:

            # sort each word into a new variable to find what the key for that iteration is
            sorted_word = "".join(sorted(word))
            
            # add each word to the sorted version, because the sorted version is the anagrams specific key
            anagram_map[sorted_word].append(word)

        # return a list of the values
        return list(anagram_map.values())