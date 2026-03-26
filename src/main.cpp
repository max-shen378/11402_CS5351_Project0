//Main program to call the two sum function
int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    std::vector<int> result = twoSum(nums, target);
    
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    
    return 0;
}