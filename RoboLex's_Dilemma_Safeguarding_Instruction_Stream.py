'''Problem Statement::==>>
In a futuristic world, a groundbreaking robot named RoboLex was built to interpret human instructions fed to it as strings. RoboLex's advanced programming allowed it to traverse the string character by character, identifying meaningful substrings that corresponded to actions. For example, encountering the substring "run" made RoboLex sprint forward, "jump" caused it to leap over obstacles, and so on.

However, RoboLex had its flaws. A critical oversight  was discovered when the word "kill" appeared in the instruction string. This caused RoboLex to mistakenly attempt destructive behaviors—an action completely unintended by its creators, who envisioned it as a harmless assistant.

To address this flaw, RoboLex's creators devised a simple rule: if "kill" appeared as a substring in the instructions, RoboLex would halt all operations. Therefore, to ensure RoboLex worked efficiently, its creators needed to remove just enough characters from the instruction string to eliminate all occurrences of "kill" while preserving as many meaningful actions as possible.

Can you help its creators determine the longest possible instruction string that RoboLex can safely execute without encountering the forbidden substring?
'''
#Topics Covered::==>>







#code::==>>
def longest_safe_string(N, S):
    # Convert the string to a list for easy modification
    S_list = list(S)
    
    # Iterate through the string to remove 'k' where necessary
    i = 0
    while i <= N - 4:  # 'kill' has 4 characters, so we only need to check up to N-4
        if S_list[i:i+4] == list("kill"):  # Check if substring is "kill"
            S_list[i] = ''  # Remove 'k' (minimum removal to break "kill")
        i += 1
    
    # Join and calculate the length of the modified string
    safe_string = ''.join(S_list)
    
    return len(safe_string)

# Example usage
N = int(input())  # Read the length of the string
S = input().strip()  # Read the instruction string
print(longest_safe_string(N, S))
