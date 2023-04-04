/*
** EPITECH PROJECT, 2023
** library MY_LAYERS
** File description:
** functions that initialize and free a layer struct
*/
#include "./include/layer.h"

layer_t * create_layer(sfVector2f size)
{
    layer_t * layer = malloc(sizeof(layer_t));
    sfColor blank = {0.0, 0.0, 0.0, 0.0};
    sfImage * image = sfImage_createFromColor(size.x, size.y, blank);
    sfTexture * texture = sfTexture_createFromImage(image, NULL);
    layer->sprite = sfSprite_create();
    sfSprite_setTexture(layer->sprite, texture, sfTrue);
    layer->texture = sfRenderTexture_create(size.x, size.y, sfTrue);
    sfRenderTexture_drawSprite(layer->texture, layer->sprite, NULL);
    sfRenderTexture_display(layer->texture);
    layer->show = true;
    layer->next = NULL;
    sfTexture_destroy(texture);
    sfImage_destroy(image);
    return layer;
}

//A->B->C->D
//A->C->B->D
void swap_layers(layer_t * layer)
{
    layer_t * nextB = layer->next;
    if (nextB == NULL) {
        return;
    }
    layer_t * nextC = nextB->next;
    if (nextC == NULL) {
        return;
    }
    layer_t * nextD = nextC->next;
    layer->next = nextC;
    nextC->next = nextB;
    nextB->next = nextD;
}

void free_layer(layer_t * layer)
{
    sfRenderTexture_destroy(layer->texture);
    sfSprite_destroy(layer->sprite);
    free(layer);
}
