texture framebuffer

effect
{
	vec4 pix = framebuffer(_in);
	
	_out = vec4(1.0 - pix.r, 1.0 - pix.g, 1.0 - pix.b, pix.a);
}
