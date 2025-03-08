TARGET_DIR="${1:-.}"

find "$TARGET_DIR" -type f -name "*.undefined" | while read -r file; do
    new_name="${file%.undefined}.cpp"
    mv "$file" "$new_name"
    echo "Renamed: $file -> $new_name"
done
echo "All matching files renamed."
