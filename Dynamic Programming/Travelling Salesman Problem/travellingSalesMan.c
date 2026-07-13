/*
Travelling Salesman Problem using Dynamic Programming
 Problem: Visit all cities exactly once and return to starting city with minimum cost
algorithm: Algorithm: Dynamic Programming (Memoization) with Bitmasking


*/


#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 20


int n;  // number of cities
int dist[MAX][MAX];  // distance matrix
int dp[1 << MAX][MAX];  // DP table

// Function to find minimum cost TSP tour
int tsp(int mask, int pos) {
    // mask = bitmask of visited cities
    // pos = current city position
    
    // Base case: all cities visited, return to city 0
    if (mask == (1 << n) - 1) {
        return dist[pos][0];  // distance from last city to starting city
    }
    
    // If already computed, return from memo
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    
    int ans = INT_MAX;
    
    // Try visiting each unvisited city
    for (int city = 0; city < n; city++) {
        // Check if city is not visited
        if ((mask & (1 << city)) == 0) {
            // Visit this city and recurse
            int new_mask = mask | (1 << city);  // mark city as visited
            int cost = dist[pos][city] + tsp(new_mask, city);
            
            // Keep minimum cost
            ans = (cost < ans) ? cost : ans;
        }
    }
    
    return dp[mask][pos] = ans;  // memoize and return
}

int main() {
    printf("===== TRAVELLING SALESMAN PROBLEM =====\n\n");
    
    // Input number of cities
    printf("Enter number of cities: ");
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Number of cities should be <= %d\n", MAX);
        return 0;
    }
    
    // Input distance matrix
    printf("\nEnter distance matrix (symmetric):\n");
    printf("Note: dist[i][j] = distance from city i to city j\n\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Distance from city %d to city %d: ", i, j);
            scanf("%d", &dist[i][j]);
        }
    }
    
    // Initialize DP table with -1 (not computed)
    memset(dp, -1, sizeof(dp));
    
    // Start TSP from city 0 with only city 0 visited
    // mask = 1 means only city 0 is visited (binary: 0001)
    int result = tsp(1, 0);
    
    printf("\n===== RESULT =====\n");
    printf("Minimum cost of TSP tour: %d\n", result);
    printf("Tour: 0 -> ... -> 0\n");
    
    return 0;
}

/*
EASY MEMORY TRICKS FOR TSP DP:
=====================================

1. STATE: dp[mask][pos]
   - mask = visited cities (0 means not visited, 1 means visited)
   - pos = current city we're at
   - Value = minimum cost from here to complete tour

2. BASE CASE: All cities visited
   - mask == (1 << n) - 1  (all bits set to 1)
   - Return distance back to city 0

3. RECURRENCE:
   - Try all unvisited cities as next destination
   - For each unvisited city: cost = dist[pos][next] + tsp(new_mask, next)
   - Take minimum

4. BITMASK OPERATIONS:
   - Check visited: (mask & (1 << city)) != 0
   - Mark visited: mask | (1 << city)
   - All visited: mask == (1 << n) - 1

5. EXAMPLE WALKTHROUGH (3 cities):
   - Start: pos=0, mask=001 (only city 0 visited)
   - Try city 1: cost = dist[0][1] + tsp(011, 1)
   - Try city 2: cost = dist[0][2] + tsp(101, 2)
   - Take minimum

TIME COMPLEXITY: O(n² × 2ⁿ)
SPACE COMPLEXITY: O(n × 2ⁿ)

SAMPLE INPUT:
4 cities
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Expected: Minimum cost (shortest tour)
*/
