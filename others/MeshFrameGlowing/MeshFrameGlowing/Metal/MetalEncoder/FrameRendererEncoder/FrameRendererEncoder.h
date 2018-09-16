//
//  FrameRendererEncoder.h
//  MeshFrame
//
//  Created by  沈江洋 on 2018/8/29.
//  Copyright © 2018  沈江洋. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>
#import <simd/simd.h>
#import "MetalContext.h"

@interface FrameRendererEncoder : NSObject

- (instancetype)initWithContext: (MetalContext *)context;
- (void)setClearColor:(const MTLClearColor) color;
- (void)setClearDepth:(const double) depth;
- (void)setThickNess: (float) thickness;
- (void)setLineColor: (const simd::float4) color;
- (void)setupFrameWithVertex: (const float *) vertices
                    andIndex: (const uint32_t *)indices
                andVertexNum: (int) vertexNum
                  andFaceNum: (int) faceNum;
- (void)setupFrameWithQuadrangleVertex: (const float *) vertices
                    andIndex: (const uint32_t *)indices
                andVertexNum: (int) vertexNum
                  andFaceNum: (int) faceNum;
- (void)encodeToCommandBuffer: (id<MTLCommandBuffer>) commandBuffer
              dstColorTexture: (id<MTLTexture>) colorTexture
              dstDepthTexture: (id<MTLTexture>) depthTexture
                   clearColor: (const BOOL) isClearColor
                   clearDepth: (const BOOL) isClearDepth
                    mvpMatrix: (simd::float4x4)mvpTransform;

@end
