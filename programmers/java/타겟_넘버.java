public int dfs(int[] numbers, int index, int tmp, int target) {
    if(numbers.length == index + 1) {
        if((tmp + numbers[index] == target) || (tmp - numbers[index] == target)) {
            return 1;
        }
        return 0;
    }

    return dfs(numbers, index+1, tmp + numbers[index], target) + dfs(numbers, index+1, tmp - numbers[index], target);
}

public int solution(int[] numbers, int target) {

    return dfs(numbers, 0, 0, target);
}
