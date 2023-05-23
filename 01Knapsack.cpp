#include<iostream>

void maximizeProfit(int profit, int weight, int *knapsack, int *capacity, int *ptr){
	if((*capacity - weight) > 0){
		*knapsack = profit;		
		*capacity = *capacity - weight;
		*ptr = *ptr + 1;
	}
}

int calculateProfit(int knapsack[], int ptr){
	int temp=0;
	for(int i=0; i<ptr; i++){
		temp = temp + knapsack[i];
	}
	return temp;
}

int main(){
	int capacity;
	std::cout << "Enter Knapsack capacity: "; std::cin >> capacity;
	
	int length;
	std::cout << "\nEnter Array size: ";
	std::cin >> length;
	
	int profit[length], weight[length], knapsack[length];
	std::cout << "\nEnter Items and profit:";
	
	for(int i=0; i < length; i++){
		std::cout << "\nItem " << i << "\nProfit: "; std::cin >> profit[i];
		std::cout << "Weight: "; std::cin >> weight[i];
	}
	
	//Assuming profit is sorted in decending order
	//max heap
	int ptr = 0;
	for(int i=0; i < length; i++){
		maximizeProfit(profit[i], weight[i], &knapsack[ptr], &capacity, &ptr);
	}
	
	int totalProfit = calculateProfit(knapsack, ptr);
	
	std::cout << "\nTotal Profit: " << totalProfit << std::endl;
    return 0; 
}