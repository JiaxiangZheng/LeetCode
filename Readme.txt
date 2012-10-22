在本地创建新的 Git 仓库
mkdir LeetCode
cd LeetCode
git init
touch README.md
git add README.md
git commit -m 'first commit'
git remote add origin git@gitcafe.com:jiaxiang.zheng/LeetCode.git
git push -u origin master
#maybe we could use git push simply
