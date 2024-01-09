/**
 * @description
 *  dfs 탐색 기반으로 나온 leaf 값을 비교하는 문제
 *  dfs 만 구현할수 있다면 크게 어려움이 있는 문제는 아니다.
 * 
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 * 
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function (rootA, rootB) {
    const aLeafs = [];
    const bLeafs = [];

    doDfs(rootA, (node, isLeafNode) => isLeafNode && aLeafs.push(node.val));
    doDfs(rootB, (node, isLeafNode) => isLeafNode && bLeafs.push(node.val));

    if (aLeafs.length !== bLeafs.length) {
        return false;
    }

    for (let i = 0; i < aLeafs.length; i++) {
        if (aLeafs[i] !== bLeafs[i]) {
            return false;
        }
    }

    return true;
};

function doDfs(treeNode, callback, isNotRoot) {
    if (!isNotRoot) {
        callback(treeNode, treeNode.left === null && treeNode.right === null);
    }

    const children = getChildren(treeNode);

    children.forEach(node => {
        callback(node, node.left === null && node.right === null);
        doDfs(node, callback, true);
    });
}

function getChildren(node) {
    var children = [];

    if (node.left) {
        children.push(node.left);
    }
    if (node.right) {
        children.push(node.right);
    }

    return children;
}
