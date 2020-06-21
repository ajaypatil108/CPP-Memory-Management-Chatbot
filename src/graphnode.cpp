#include "graphedge.h"
#include "graphnode.h"

#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode(){}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}


void GraphNode::MoveChatbotHere(ChatBot bot_on_node)
{
    // move chatbot instance into current node with move assignment operator
    _chatBot = std::move(bot_on_node);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // move _chatbot to a new node by using the function above
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    // utilize .get() method of smart pointers since _childEdges is vector of smart unique pointers
    return (_childEdges[index]).get();
}