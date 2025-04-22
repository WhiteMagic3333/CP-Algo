import base64

base64_string = "_S4X7B,_U3M3xR9i7BvX2U753PW1t738zzr8R2,_Q60jC12WN9SZ4rEv138o5C16Q8arCodeAt,_Za9DFOVlht1GcVVL4N9m3kq,_D1kYL3RzgnM7haJc4R92x1t67L92ag4tFBOE72w,_CSgW2h408JE8rsx9h4xZ2qQ6Acwt0SmsS7IVzB2C71LkMLnM,_LGEdn7HP802OCzxG2g2w9f1r8UC7l5aOnmspkV8,_XP489McA4MnS"

# Your base64 string (replace this with your actual Base64 string)
# base64_string = encoded  # This is the Base64 encoded version of "Hello world!"

# Decode the Base64 string
decoded_bytes = base64.b64decode(base64_string)

# Convert the bytes to a string (assuming it's a UTF-8 encoded string)
decoded_string = decoded_bytes.decode('utf-8')

# Print the decoded string
print(decoded_string)


