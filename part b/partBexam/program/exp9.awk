BEGIN{
count=0;
}
{
if($1 == "d")
count++
}
END{
print("The Total no of Packest Drop is : ",count);
}
