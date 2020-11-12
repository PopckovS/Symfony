<?php

namespace App\Entity;

use App\Repository\TaskRepository;
use Doctrine\ORM\Mapping as ORM;

use ApiPlatform\Core\Annotation\ApiResource;        // API Platform
use Symfony\Component\Serializer\Annotation\Groups; // Сериалайзер для создания групп
use ApiPlatform\Core\Annotation\ApiFilter;          // Класс для создания фильтра в аннотациях, для работы Api platform.

use ApiPlatform\Core\Bridge\Doctrine\Orm\Filter\SearchFilter; // 2 фильтра для для обычного поиска и для
use ApiPlatform\Core\Bridge\Doctrine\Orm\Filter\DateFilter;   // поиска по дате времени.


/**
 * @ORM\Entity(repositoryClass=TaskRepository::class)
 *
 * @ApiResource(
 *     normalizationContext={
 *                  "groups"={"task"}},
 *                  attributes={"order"={"planned_finished_at": "DESC"},
 *     "pagination_enabled"=false}
 *     )
 * @ApiFilter(SearchFilter::class, properties={"id":"exact", "title":"exact", "content":"exact"})
 *
 * @ApiFilter(DateFilter::class, properties={"planned_finished_at"})
 */
class Task
{

    /**
     * @ORM\Id
     * @ORM\GeneratedValue
     * @ORM\Column(type="integer")
     * @Groups({"task"})
     */
    private $id;

    /**
     * @ORM\Column(type="string", length=255, nullable=true)
     * @Groups({"task"})
     */
    private $title;

    /**
     * @ORM\Column(type="text", nullable=true)
     * @Groups({"task"})
     */
    private $content;

    /**
     * @ORM\Column(type="datetime", nullable=true)
     * @Groups({"task"})
     */
    private $planned_finished_at;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getTitle(): ?string
    {
        return $this->title;
    }

    public function setTitle(?string $title): self
    {
        $this->title = $title;

        return $this;
    }

    public function getContent(): ?string
    {
        return $this->content;
    }

    public function setContent(?string $content): self
    {
        $this->content = $content;

        return $this;
    }

    public function getPlannedFinishedAt(): ?\DateTimeInterface
    {
        return $this->planned_finished_at;
    }

    public function setPlannedFinishedAt(?\DateTimeInterface $planned_finished_at): self
    {
        $this->planned_finished_at = $planned_finished_at;

        return $this;
    }
}
