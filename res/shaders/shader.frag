#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform vec2 textureSize;

float checkerboard(vec2 uv, vec2 textureSize){
      float cx = floor(textureSize.x * uv.x);
      float cy = floor(textureSize.y * uv.y);
      float result = mod(cx + cy, 2.0);
      return sign(result);
}

void main()
{
    vec2 uv = TexCoord.xy;
    uv.x *= textureSize.x / textureSize.y;
    float c = mix(1.0, 0.0f, checkerboard(uv, textureSize));
    FragColor = vec4(c,c,c,1.0);
}
