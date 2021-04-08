# minirt

## 프로세스 흐름

- 인자 에러처리
- rt파일 파싱
  - 예외 발생 시 error_msg print & exit
  - world init
- rendering
  - while (픽셀 끝까지)
    - hit : return(t_bool) / 핵심 기능 : primary ray로 오브젝트 순회하며 hit여부 판단하여 hit_record에 기록
    - while (light)
      - light = sum(phong_lighting) : return(t_color) hit_point 에서 shadow_ray를 생성하여 오브젝트 순회하며 hit 여부 판단, !hit 면 light color return, hit 면 color(0,0,0) return
    - pixel_color = object_albedo * light_sum
    - write_pixel_color_on_mlx_image
- mlx_put_image_to_window

iloveyou