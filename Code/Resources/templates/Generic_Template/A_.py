def update_query(arr, rev, i, j):
    """
    Swaps elements at positions i and j in the main array (arr) 
    and its reverse counterpart (rev).
    """
    n = len(arr)
    rev_i = n - i - 1
    rev_j = n - j - 1
    arr[i], arr[j] = arr[j], arr[i]
    rev[rev_i], rev[rev_j] = rev[rev_j], rev[rev_i]


def query_game(N, A, Q, P):
    """
    Processes queries on array A with efficient handling of reverse and swaps.
    """
    rev = A[::-1]  # Reverse array as a shadow copy
    is_reversed = False  # Tracks if the array is logically reversed
    results = []

    for query in P:
        op = query[0]
        if op == 1:
            # Toggle the reversed state
            is_reversed = not is_reversed

        elif op == 2:
            # Swap elements at positions i and j
            _, i, j = query
            i -= 1  # Convert to 0-based index
            j -= 1
            if is_reversed:
                update_query(rev, A, i, j)
            else:
                update_query(A, rev, i, j)

        elif op == 3:
            # Output the element at position i
            _, i = query
            i -= 1  # Convert to 0-based index
            if is_reversed:
                results.append(rev[i])
            else:
                results.append(A[i])

    return results


# Driver code to handle multiple test cases
T = int(input())  # Number of test cases
for _ in range(T):
    N = int(input())  # Size of the array
    A = list(map(int, input().split()))  # The array
    Q = int(input())  # Number of queries
    P = [list(map(int, input().split())) for _ in range(Q)]  # List of queries
    
    # Process the queries
    out_ = query_game(N, A, Q, P)
    
    # Print the results for all type 3 queries
    print(' '.join(map(str, out_)))