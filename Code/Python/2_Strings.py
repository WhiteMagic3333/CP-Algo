# almost same
print('Alice' + 'Bob')
print("Alice" + "Bob")

# In Python, both single quotes ('') and double quotes ("") are used to represent string literals,
# and they function the same way in most cases. There is no functional difference between them. 
# You can use either one to create a string:
# string1 = 'Hello'
# string2 = "Hello"
# Both string1 and string2 are valid strings containing the text "Hello".
# Why Use One Over the Other?
# The choice between single or double quotes is generally a matter of personal preference or coding style,
# but there are a few practical reasons to choose one over the other:

# Convenience with String Containing Quotes:
# If your string contains a single quote ('), you might prefer using double quotes 
# (") to avoid needing to escape the single quote:
# string = "It's a great day!"
# Similarly, if the string contains double quotes ("), you can use single quotes (') to avoid escaping the double quotes:
# string = 'She said "Hello" to me.'
# Consistency:

# Many style guides, such as PEP 8, don't prescribe a strict rule but suggest consistency within a project. 
# It's good practice to stick to one type of quote for consistency.
# Escaping Characters:

# If you need to include both types of quotes within a string, you can escape them using the backslash (\):
# string = 'He said "Hello" and then left.'
# string2 = "It's a beautiful day."
# Summary:
# Both '' and "" represent strings and can be used interchangeably.
# The choice between them is often based on convenience (to avoid escaping quotes within the string) or stylistic preference.


# Error = String + int
# print('Alice' + 42)


# Repeating
print('Alice' * 3)

# Error = String * string or String * float
# print('Alice' * 'Bob')
# print('Alice' * 5.0)

