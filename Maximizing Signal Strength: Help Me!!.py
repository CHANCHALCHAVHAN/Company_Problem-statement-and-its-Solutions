'''PROBLEM STATEMENT:==>>
Problem Statement
An explorer is lost on a remote island in the middle of a vast sea. They find a small device that can send a distress signal to call for help. However, the device is low on power and can’t run all its parts at once.

The device has N components, each with an energy efficiency value. To make the signal as strong as possible, the explorer decides to turn off one out of every five components. The strength of the signal depends on the average efficiency of the components still running.

The explorer must carefully choose which components to turn off so the average efficiency of the remaining ones is as high as possible.

Can you figure out which components the explorer should turn off to maximize the signal’s average strength?

Note:

Each component’s efficiency value is an integer.
The number of components is always a multiple of five.
The answer should show the highest possible average efficiency, rounded to five decimal places.
'''
#CODE==>
def maximize_average_efficiency(n, efficiencies):
    if n < 5:
        return 0.00000
    
    num_remove = n // 5  # Number of components to remove
    efficiencies.sort()  # Sort in ascending order
    
    # Remove the lowest 'num_remove' components
    remaining_efficiencies = efficiencies[num_remove:]
    
    # Calculate the average efficiency of remaining components
    avg_efficiency = sum(remaining_efficiencies) / len(remaining_efficiencies)
    
    # Print the result rounded to five decimal places
    return f"{avg_efficiency:.5f}"

# Read input
n = int(input())
efficiencies = list(map(int, input().split()))

# Compute and print the result
print(maximize_average_efficiency(n, efficiencies))
