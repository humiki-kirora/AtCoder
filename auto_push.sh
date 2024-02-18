git add .
git commit -m $1
$branch=$(git branch --contains=HEAD | cut -d " " -f 2)
git push origin $branch