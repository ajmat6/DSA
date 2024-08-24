let arr = [1, 2, 3, 5];
let reducteFunctions = arr.reduce((a, b) => {
    return a + b;
}, 0);
console.log(reducteFunctions);