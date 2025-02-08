
#!/bin/bash

# 탐색할 디렉토리 (기본값: 현재 디렉토리)
TARGET_DIR="${1:-.}"

# find를 사용하여 ".undefined"로 끝나는 파일 찾기
find "$TARGET_DIR" -type f -name "*.cc" | while read -r file; do
    # 새로운 파일명 생성 (.cc 확장자로 변경)
    new_name="${file%.cc}.cpp"
    
    # 파일명 변경
    mv "$file" "$new_name"
    
    # 변경된 파일명 출력
    echo "Renamed: $file -> $new_name"
done

echo "All matching files renamed."
