#include "stdafx.h"
#include "SceneNode.h"
#include "Visitor.h"

using namespace Math;

SceneNode::SceneNode() : m_RenderArgs(nullptr)
{
}

void SceneNode::Accept( Visitor& visitor )
{
    visitor.Visit( *this );
    for (auto child : m_Children)
        child->Accept( visitor );
}

void SceneNode::AddChild( std::shared_ptr<SceneNode> pNode )
{
    m_Children.push_back( pNode );
}

void SceneNode::Render( GraphicsContext& gfxContext, Visitor& visitor )
{
    (gfxContext), (visitor);
}

void SceneNode::RenderBone( GraphicsContext& gfxContext, Visitor& visitor )
{
    (gfxContext), (visitor);
}

void SceneNode::Update( float deltaT )
{
    (deltaT);
}

void SceneNode::UpdateAfterPhysics( float deltaT )
{
    (deltaT);
}

Matrix4 SceneNode::GetTransform() const
{
    return Matrix4( kIdentity );
}

void SceneNode::SetTransform( const Math::Matrix4& )
{
}
