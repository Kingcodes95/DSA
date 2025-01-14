# Dictionary (map)

# Key - value pairs
# example: {"name": "Alice", "Age": 25}

# mutable: Can add, modify, or remove items

# Keys must be unique

# Dictionarys are ideal when:

# - Fast lookups O(1)
# - data has meaningfull associations
# - Grouping or counting data

# how to use:

# - use curly braces
# Person = {}

# - dict() constructor
# person = dict(name="alice"m age=25, city="New york")

# Adding or updating:
# person["age"] = 26
# or you can just create the variable and set it to a value to add a new key value pair

# Removing:
# person.pop("age") removes "age" key and returns it value
# del person["city"] removes "city" key

# iterating:
# for key in person:
#     pring(key, person[key])

# Checking Existance:

# if "Name" in person: